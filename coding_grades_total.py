from __future__ import print_function
import re


def get_ok_num_perq(tresfile):
    file = open(tresfile,"r")
    cnt = 0
    f = file.read()
    lists = f.split("\n")
    
    for i in lists:
        if i:
            cnt += 1
    
    return cnt

total_coding_score = 0.0;

q_nums = [1, 2, 3, 4]

for q_num in q_nums:
	pass_num = get_ok_num_perq("grades/Q%dres_.txt" % q_num)

	if q_num == 1:
		if pass_num <= 13:
			q1_score = pass_num * 2
		elif pass_num == 14:
			q1_score = 30
		print("Q1:", pass_num, "/", 14, "passed | score:", q1_score)
		total_coding_score += q1_score
	elif q_num == 2:
		f pass_num <= 8:
			q1_score = pass_num * 3
		elif pass_num == 9:
			q1_score = 30
		print("Q2:", pass_num, "/", 1, "passed | score:", q2_score)
		total_coding_score += q2_score
	elif q_num == 3:
		if pass_num <= 6:
			q3_score = pass_num * 4
		elif pass_num == 7:
			q3_score = 30
		print("Q3:", pass_num, "/", 7, "passed | score:", q3_score)
		total_coding_score += q3_score
	elif q_num == 4:
		if pass_num <= 16:
			q4_score = pass_num * 1.5
		elif pass_num == 17:
			q4_score = 30
		print("Q4:", pass_num, "/", 17, "passed | score:", q4_score)
		total_coding_score += q4_score
	else:
		raise ValueError('Wrong question number')


print("-----------------------------------------")
print("Your total score of coding section:", total_coding_score)
print("-----------------------------------------")
