
finding mex in the array (first non negative number in the set)

add x to set    o(logn)
delete y from the set o(logn)
find the mex of the set o(logn)


set<int> compliment; # initally consists of all elements in n;

map stores freq.
map[ele]= freq
if element is added to set delete from the complimemnt..it can never
be mex.

=========================if only insertions are made==============

unordered_map<int,int> m;

initally mex=0 ...after insertions into the array
then increment mex the accordingly

