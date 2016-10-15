#include <iostream>
#include <map>

using namespace std;

static map<int, int> f_memo;
static map<int, int> f1_memo;

/* f1(n) = 0 (n<10)
 *       | f1(n div 10) + (n mod 10) (else) */
int f1(int k) {
  if (f1_memo.find(k) != f1_memo.end()) return f1_memo[k];

  cout << "f1(" << k << "),";

  if (k < 10) {
    f1_memo[k] = k;
    return k;
  }

  div_t d = div(k, 10);
  int f1_k = f1(d.quot) + d.rem;
  f1_memo[k] = f1_k;
  return f1_k;
}

/* f(n) = 0 (n < 10)
 *      | 1 + f(f1(n)) (else) */
int f(int k)
{
  if (f_memo.find(k) != f_memo.end()) return f_memo[k];

  cout << "f(" << k << "),";

  if (k < 10) {
    f_memo[k] = 0;
    return 0;
  }

  int f_k = f(f1(k)) + 1;
  f_memo[k] = f_k;
  return f_k;
}

/* g(n) = 0 (n=0)
 *      | f(n) + g(n-1) (else) */
int g(int n)
{
  int sum = 0;
  for (int i = 0; i <= n; ++i) {
    sum += f(i);
  }
  return sum;
}

int main()
{
  int n;
  cin >> n;
  int g_n = g(n);
  cout << endl;
  cout << g_n;
}
