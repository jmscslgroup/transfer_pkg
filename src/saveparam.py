#!/usr/bin/env python
# 
# Author: Rahul Bhadani
# Copyright (c) Arizona Board of Regents
# All rights reserved.

import sys
import rospy
import csv
import time
import datetime
import socket
from os.path import expanduser

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
    
    param_list = []
    val_list = []
    
    for p in params:
        param_list.append(p)
        val = rospy.get_param(p)
        val_list.append(val)
    
    dt_object = datetime.datetime.fromtimestamp(time.time())
    filename  = dt_object.strftime('%Y_%m_%d_%H_%M_%S')  + '_rosparams_' + argv[0] + '.csv'
    parentfolder = dt_object.strftime('%Y_%m_%d') + '/'
    host = socket.gethostname()
    
    home = expanduser("~")

    if host in ['refulgent', 'ivory']:
        filename = home  +'/.ros/' + parentfolder + filename
    else:
        filename = '/var/panda/CyverseData/JmscslgroupData/bagfiles/' + parentfolder + filename
    
    print(filename)
    with open(filename, 'w') as csvfile: 
        # creating a csv writer object 
        csvwriter = csv.writer(csvfile) 
        
        # writing the fields 
        csvwriter.writerow(param_list) 
        
        # writing the data rows 
        csvwriter.writerow(val_list)

if __name__ == '__main__':
    main(sys.argv[1:])
    
