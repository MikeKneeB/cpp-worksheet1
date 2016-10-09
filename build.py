#!/usr/bin/python

# Python script to build files in worksheet1 to source.
#
# make is an awful language and I refuse to use it. cmake is no better.
# 


import argparse
from subprocess import call

parser = argparse.ArgumentParser(description='Build automater written by Mike Knee')

parser.add_argument('--flags', nargs='*', help='Specify non-default compiler flags. The "-" should be omitted.')
parser.add_argument('--suppress-flags', help='Suppress default compiler switches', action='store_true')
parser.add_argument('--sources', nargs='*', help='List of specific sources to compile.')

compiler="g++"
compiler_flags=["-Wall", "-O2"]
source_dir="source/"
object_dir="images/"

executables_to_compile={"w1q2.cpp" : "hello",
        "w1q3a.cpp" : "maxint",
        "w1q3b.cpp" : "maxfloat",
        "w1q3c.cpp" : "difference",
        "w1q3d.cpp" : "sums",
        "w1q4.cpp" : "silverratio"}

print "Beginning build."

args = parser.parse_args()

print args

if args.sources==None:
    
    for source_file in executables_to_compile:
        exe_list = [compiler, "-o", object_dir+executables_to_compile[source_file], source_dir+source_file]
        if args.suppress_flags==False:
            exe_list[1:1] = compiler_flags 
        if not args.flags==None:
            for item in args.flags:
                exe_list.insert(1, "-"+item)
        print exe_list
        call(exe_list)

else:

    for item in args.sources:
        exe_list = [compiler, "-o", object_dir+executables_to_compile[item], source_dir+item]
        if args.suppress_flags==False:
            exe_list[1:1] = compiler_flags 
        if not args.flags==None:
            for item in args.flags:
                exe_list.insert(1, "-"+item)
        print exe_list
        call(exe_list)
