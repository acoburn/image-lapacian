\name{laplace}
\alias{laplace}
\title{The Laplace Distribution}
\description{
    A distribution function for the laplace distribution with mean equal to mean and the scaling factor equal to b.
}
\usage{
laplace(x, mean = 0, b = 1)
}
\arguments{
  \item{x}{
      A vector of numerical values
}
  \item{mean}{
      The mean value of the distribution
}
  \item{b}{
      The scaling factor
}
}
\value{
    Returns the density of the input vector.
}
\references{
    \url{http://www.encyclopediaofmath.org/index.php/Laplace_distribution}
}
\author{
    Aaron Coburn <acoburn@amherst.edu>
}
\examples{
## The function is currently defined as
function (x, mean = 0, b = 1) 
{
    sapply(x, function(y) {
        (1/(2 * b)) * exp(-abs(y - mean)/b)
    })
  }
}
\keyword{statistics}
