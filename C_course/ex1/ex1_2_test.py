import subprocess
import os
import filecmp


test_dir = "DrawPolynomial/"
test_file_out = "draw%s.out"
test_file_in = "draw%s.in"

files_range = 10
test_out_fn = "test.out"
c_run = "./ex1_2"

# subprocess.Popen([c_run, "<", test_dir + "draw1.in"], stdout=out) // check why this wont work

for x in range(files_range):
    x = x+1
    input_file = open(test_dir + test_file_in%(x), "r")
    out = open("test.out","w+")
    p = subprocess.Popen([c_run], stdout=out, stdin=input_file)
    p.communicate()
    out.close()
    input_file.close()
    if not filecmp.cmp('test.out', test_dir+test_file_out%(x)):
        print "draw %s" %(x) , "false"
    else:
        print "draw %s" %(x) , "true"
