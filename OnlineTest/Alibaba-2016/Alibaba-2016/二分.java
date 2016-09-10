while(x<=y) {
m = x + (y-x)/2; //2
if(data[m] == v) return m; //3
else if(data[m] > v) y = m-1; //4
else x = m+1; //5
}