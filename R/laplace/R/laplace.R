dlaplace <-
function(x, mean = 0, b = 1) {
    sapply(x, function(y) { (1 / (2 * b)) * exp(- abs(y - mean) / b) })
}
