//   count the number of 1s in the binary representation of an integer



int countSetBits(int num){
  int count = 0;
  while(n){
    n &= (n-1);
    count++;
  }
  return count;
}



//    concept
//    if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit
