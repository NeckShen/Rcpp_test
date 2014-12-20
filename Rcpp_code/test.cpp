#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
SEXP num_cpp(NumericVector idx) {
  std::vector<double> y(30);
  std::vector<int> tmp(idx==1);
  tmp = tmp / 10;
  std::partial_sum(tmp.begin(), tmp.end(), y.begin());
  return(wrap(tmp))
}
/*** R
library(Rcpp)
y = rnorm(30)
x = rep(c(1:3),each=10)
x = x[order(y)]
print(num_cpp(x))
*/
