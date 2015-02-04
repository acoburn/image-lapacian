# Compute a laplace distribution for an input vector.
library("laplace")

scale <- 1
mean <- 0

x <- seq(-8, 8, length = 9)
y <- dlaplace(x, mean, scale)

Filter(function (x) { x > 0.0001 }, y)
