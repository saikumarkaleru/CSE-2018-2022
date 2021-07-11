/*

Given an array of n integers where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates. There are m students, the task is to distribute 
chocolate packets such that:
 
Each student gets one packet.

The difference between the number of chocolates in the packet with maximum chocolates and 
packet with minimum chocolates given to the students is minimum.








An efficient solution is based on the observation that to minimize the difference,
we must choose consecutive elements from a sorted packet. We first sort the array arr[0..n-1], 
then find the subarray of size m with the minimum difference between the last and first elements.




*/















