# Compute a laplace distribution for an input vector.
laplace <- function(vec, m, b) {
    sapply(vec, function(v) { (1 / (2 * b)) * exp(- abs(v - m) / b) })
}

scale <- 1
mean <- 0

x <- seq(-4, 4, length = 100)
y <- laplace(x, mean, scale)
