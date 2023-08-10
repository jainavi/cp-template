// int curr_l = 1, curr_r;

// bool compare(Q q1, Q q2)
// {
//     if (q1.l / rootN == q2.l / rootN)
//     {
//         return q1.r > q2.r;
//     }
//     return q1.l / rootN < q2.l / rootN;
// }


// void update(Q q)
// {
//     while (curr_l < q.l)
//     {
//         removeElement(curr_l - 1);
//         curr_l++;
//     }
//     while (curr_l > q.l)
//     {
//         curr_l--;
//         addElement(curr_l - 1);
//     }
//     while (curr_r < q.r)
//     {
//         curr_r++;
//         addElement(curr_r - 1);
//     }
//     while (curr_r > q.r)
//     {
//         removeElement(curr_r - 1);
//         curr_r--;
//     }
// }

// sort(arrQ, arrQ + q, compare);