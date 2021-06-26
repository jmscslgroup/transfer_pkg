#!/usr/bin/env python
# 
# Author: Rahul Bhadani
# Copyright (c) Arizona Board of Regents
# All rights reserved.

import sys
import rospy
import pandas as pd
import time
import datetime
import socket

class saveparam:
    def __init__(self, ns):
        """
        """
        pass


def main(argv):
    

    print("In Save param")
    rospy.init_node('saveparam', anonymous=True)
    ns = rospy.get_namespace() # Retrieve the name space
    params = rospy.get_param_names()
    
    param_dict = {}
    
    
    for p in params:
        val = rospy.get_param(p)
        param_dict[p] = val

    df = pd.DataFrame.from_dict(param_dict, orient='index', columns=['ParameterValue'])
    
    dt_object = datetime.datetime.fromtimestamp(time.time())
    filename  = dt_object.strftime('%Y-%m-%d-%H-%M-%S-%f')  + '_fieldtest_rosparams.csv'
    parentfolder = dt_object.strftime('%Y_%m_%d') + '/'
    host = socket.gethostname()
    if host in ['refulgent', 'ivory']:
        filename = '~/.ros/' + filename
    else:
        filename = '/var/panda/CyverseData/JmscslgroupData/bagfiles/' + parentfolder + filename
    
    df.index.name  = 'ParameterName'
    print(df)
    df.to_csv(filename)

if __name__ == '__main__':
    main(sys.argv[1:])
    
