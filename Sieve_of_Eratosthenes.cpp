// Count the number of prime numbers less than a non-negative number, n



int countPrimes(int n) {
    if(n<=2) return 0;
    int count=1, m=n/2;
    vector<bool> v(m, 1);
    int curr, index;
    for(int i=1; i<m; i++){
        if(!v[i]) continue;
        curr = 2*i + 1;
        count++;
        if(curr > sqrt(n)) continue;
        for(int j=curr*curr; j<n; j += curr){
            if(j&1){
                index = (j-1)/2;
                v[index] = 0;
            }
        }
    }
    return count;
}



// Algorithm
// Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
// Let p be the variable we use in the outer loop that iterates from 2 to sqrt{n} 
// Initially, let p equal 2, the smallest prime number.
// Enumerate the multiples of p by counting in increments of p from p*p to n, and mark them in the list (these will be p*p, p*p + p, p*p + 2*p, ...; p itself should be prime).
// Find the smallest number in the list greater than p that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
// When the algorithm terminates, all of the remaining numbers that are not marked are prime.



// Time Complexity: The overall time complexity is O(sqrt{n}loglogn))
// Space Complexity: O(n)
