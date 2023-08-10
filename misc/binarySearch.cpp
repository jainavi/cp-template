// while(lo < hi) {
// int mid = lo + (hi - lo) / 2;
// if(Special condition passed)(optional):
// 	return mid; 
// if(condition passed)
//   hi = mid;
// else 
//   lo = mid + 1;
// }
// return lo;

// NOTE: the range for searching is [s, e) where e is not included

// The key idea is that the range of searching is monotonic, i.e., If F(a) == true, 
// then for every b > a, F(b) = true. So our goal is to find the leftmost point a that F(a) == true, 
// which can be solved by binary search. In order to find the leftmost point which satisfies the condition, 
// do not break the loop immediately when u find a valid point (There may exist some valid points on 
// the left side). Instead, what u can do is to narrow the searching range