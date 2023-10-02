#!/usr/bin/python
# -*- coding: utf-8 -*-
# awshelper.py
# It has methods for managing AWS EC2 instances.
# It uses Client API (low-level) of Boto3.

import sys
import boto3
import botocore

region = 'eu-west-1'    # AWS region

def describe_instances():
    """
    Describes all EC2 instances associated with an AWS account
    """
    # Create an EC2 Client
    ec2_client = boto3.client('ec2', region_name=region)
    # Describe instances
    response = ec2_client.describe_instances()
    print(response)
    print('\nInstances:')
    for i in response['Reservations']:
        for j in i['Instances']:
            print('state of the instance "' + j['InstanceId'] + '" is: "' + j['State']['Name'] + '"')
    return


def run_instance():
    """
    Run an EC2 instance
    """
    ami_id        = "ami-785db401"   # AMI Id
    instance_type = "t2.micro"       # Instance Type

    # Create an EC2 Client
    ec2_client = boto3.client('ec2', region_name=region)
    # Run an instance
    response = ec2_client.run_instances(ImageId=ami_id, InstanceType=instance_type,
                                       MaxCount=1, MinCount=1)
    print(response)
    Instance_id = response['Instances'][0]['InstanceId']
    print('\nInstance Id:      ' + Instance_id)
    print('Image Id:         ' + response['Instances'][0]['ImageId'])
    print('Instance Type:    ' + response['Instances'][0]['InstanceType'])
    print('State:            ' + response['Instances'][0]['State']['Name'])

    return Instance_id


def describe_instance(instance_id):
    """
    Describes an EC2 instance
    """
    # Create an EC2 Client
    ec2_client = boto3.client('ec2', region_name=region)
    try:
        # Describe an instance
        response = ec2_client.describe_instances(InstanceIds=[instance_id])
        print(response)
        print('\nInstance Id:      ' + instance_id)
        print('Instance Id:      ' + response['Reservations'][0]['Instances'][0]['InstanceId'])
        print('Image Id:         ' + response['Reservations'][0]['Instances'][0]['ImageId'])
        print('Instance Type:    ' + response['Reservations'][0]['Instances'][0]['InstanceType'])
        print('State:            ' + response['Reservations'][0]['Instances'][0]['State']['Name'])
        if response['Reservations'][0]['Instances'][0]['State']['Name'] == 'running':
            print('Private DNS Name: ' + response['Reservations'][0]['Instances'][0]['PrivateDnsName'])
            print('Private IP:       ' + response['Reservations'][0]['Instances'][0]['PrivateIpAddress'])
            print('Public DNS Name:  ' + response['Reservations'][0]['Instances'][0]['PublicDnsName'])
            print('Public IP:        ' + response['Reservations'][0]['Instances'][0]['PublicIpAddress'])
    except botocore.exceptions.ClientError as e:
        if e.response['Error']['Code'] == "MissingParameter":
            print("Error: Missing instance id!!")
        else:
            raise
    return


def start_instance(instance_id):
    """
    Start an EC2 instance
    """
    # Create an EC2 Client
    ec2_client = boto3.client('ec2', region_name=region)
    try:
        # Start an instance
        response = ec2_client.start_instances(InstanceIds=[instance_id], DryRun=False)
        print(response)
        print("\nSuccessfully starting instance: ", instance_id)
    except botocore.exceptions.ClientError as e:
        if e.response['Error']['Code'] == "InvalidInstanceID.Malformed":
            print("Error: Invalid instance id!!")
        else:
            raise
    return


def stop_instance(instance_id):
    """
    Stop an EC2 instance
    """
    # Create an EC2 Client
    ec2_client = boto3.client('ec2', region_name=region)
    try:
        # Stop an instance
        response = ec2_client.stop_instances(InstanceIds=[instance_id], DryRun=False)
        print(response)
        print("\nSuccessfully stopping instance: ", instance_id)
    except botocore.exceptions.ClientError as e:
        if e.response['Error']['Code'] == "InvalidInstanceID.Malformed":
            print("Error: Invalid instance id!!")
        else:
            raise
    return


def reboot_instance(instance_id):
    """
    Reboot an EC2 instance
    """
    # Create an EC2 Client
    ec2_client = boto3.client('ec2', region_name=region)
    try:
        # Reboot an instance
        response = ec2_client.reboot_instances(InstanceIds=[instance_id], DryRun=False)
        print(response)
        print("\nSuccessfully rebooting instance: ", instance_id)
    except botocore.exceptions.ClientError as e:
        if e.response['Error']['Code'] == "InvalidInstanceID.Malformed":
            print("Error: Invalid instance id!!")
        else:
            raise
    return


def terminate_instance(instance_id):
    """
    Terminate an EC2 instance
    """
    # Create an EC2 Client
    ec2_client = boto3.client('ec2', region_name=region)
    try:
        # Terminate an instance
        response = ec2_client.terminate_instances(InstanceIds=[instance_id], DryRun=False)
        print(response)
        print("\nSuccessfully terminating instance: ", instance_id)
    except botocore.exceptions.ClientError as e:
        if e.response['Error']['Code'] == "InvalidInstanceID.Malformed":
            print("Error: Invalid instance id!!")
        else:
            raise
    return
