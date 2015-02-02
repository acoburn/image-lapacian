#include <vector>
#include <set>
#include <cmath>
#include <map>

namespace laplacian {

    class Laplacian {
        const float epsilon;
        const std::map<int, std::set<int> > matrix;
        std::vector<float> y1;
        std::vector<float> y2;

        public:
            Laplacian(const std::map<int, std::set<int> > &sparseMatrix) :
                matrix(sparseMatrix), epsilon(0.0000007) { }

            Laplacian(const std::map<int, std::set<int> > &sparseMatrix, const float epsilon) :
                matrix(sparseMatrix), epsilon(epsilon) { }

            std::vector<float> getEigenVectorFirst() {
                return y1;
            }

            std::vector<float> getEigenVectorSecond() {
                return y2;
            }

            // we create the Adjacency matrix A
            // we compute the Second and Third smallest Eigenvalues and vectors of the Laplacian
            // L = D - A. We actually use gI-L, where g is found using Gershgorian...
            void computEigenVectors() {
                int** A = new int* [matrix.size()]; 
                std::vector<int> RowSizes(matrix.size());

                std::map< int, std::set<int> >::const_iterator m = matrix.begin();
                std::set<int>::const_iterator p;
                while (m != matrix.end()) {
                    RowSizes[m->first] = m->second.size();
                    int j = 0;
                    A[m->first] = new int[m->second.size()];
                    for (p = m->second.begin(); p != m->second.end(); p++)
                        A[m->first][j++] = *p;
                    m++;
                }

                int N = matrix.size();
                int i, j;
                float lambda1, lambda2, lambdaOld, Norm;

                int g;
                // find value of g
                int max = 0;
                for(i = 0; i < N; i++)
                    if (RowSizes[i] > max) max = RowSizes[i];
                g = 2 * max;

                std::vector<float> u1(N);
                std::vector<float> u1hat(N);
                std::vector<float> u2(N);
                std::vector<float> u2hat(N);
                std::vector<float> v(N);

                for(i = 0; i < N; i++)
                    v[i] = 1;
                
                // normalize
                Norm = norm(v);
                for(i = 0; i < N; i++)
                    v[i] /= Norm;

                // Compute second eigenvector
                // initialize with random vector
                for(i = 0; i < N; i++)
                    u1hat[i] = (float)rand()/RAND_MAX;

                // normalize
                Norm = norm(u1hat);
                for(i = 0; i < N; i++)
                    u1hat[i] /= Norm;

                lambda1 = 1.0;
                int iterations = 0;
                do {
                    iterations++;
                    lambdaOld = lambda1;
                    for(i = 0; i < N; i++)
                        u1[i] = u1hat[i];

                    // orthogonalize against v
                    float innerProd = 0;
                    for(i = 0; i < N; i++)
                        innerProd += v[i] * u1[i];
                    for(i = 0; i < N; i++)
                        u1[i] += -innerProd * v[i];

                    // u1hat = Au1
                    for(i = 0; i < N; i++) {
                        u1hat[i] = (g - RowSizes[i]) * u1[i];
                        for(j=0; j < RowSizes[i]; j++) {
                            u1hat[i] += u1[A[i][j]];
                        }
                    }

                    // compute eigenvalue
                    lambda1 = 0;
                    for(i = 0; i < N; i++)
                        lambda1 += u1hat[i] * u1[i];

                    // normalize
                    Norm = norm(u1hat);
                    for(i = 0; i < N; i++)
                        u1hat[i] /= Norm;

                } while(fabsf((lambda1-lambdaOld)/lambda1) > epsilon && iterations < 150);

                for(i = 0; i < N; i++)
                    y1[i] = u1hat[i];

                // Compute third eigenvector
                // initialize with random vector
                for(i = 0; i < N; i++)
                    u2hat[i] = (float)rand()/RAND_MAX;
                
                // normalize
                Norm = norm(u2hat);
                for(i = 0; i < N; i++)
                    u2hat[i] /= Norm;

                lambda2 = 1.0;
                iterations = 0;
                do {
                    iterations++;
                    lambdaOld = lambda2;
                    for(i = 0; i < N; i++)
                        u2[i] = u2hat[i];

                    // orthogonalize against v
                    float innerProd = 0;
                    for(i = 0; i < N; i++)
                        innerProd += v[i] * u2[i];

                    for(i = 0; i < N; i++)
                        u2[i] += -innerProd * v[i];
                    
                    // orthogonalize against u2hat
                    innerProd = 0;
                    for(i = 0; i < N; i++)
                        innerProd += u1hat[i] * u2[i];
                    
                    for(i = 0; i < N; i++)
                        u2[i] += -innerProd * u1hat[i];

                    // y2 = Au2
                    for(i = 0; i < N; i++) {
                        u2hat[i] = (g - RowSizes[i]) * u2[i];
                        for(j=0; j < RowSizes[i]; j++) {
                            u2hat[i] += u2[A[i][j]];
                        }
                    }

                    // compute eigenvalue
                    lambda2 = 0;
                    for(i = 0; i < N; i++)
                        lambda2 += u2hat[i] * u2[i];

                    // normalize
                    Norm = norm(u2hat);
                    for(i = 0; i < N; i++)
                        u2hat[i] /= Norm;

                } while(fabsf((lambda2-lambdaOld)/lambda2) > epsilon && iterations < 150);
                
                for(i = 0; i < N; i++)
                    y2[i] = u2hat[i];

                for (int i = 0; i < matrix.size(); i++)
                    delete A[i];
                delete A;
            }

        private:
            float norm(std::vector<float>& v)
            {
                float sum = 0;
                for (std::vector<float>::iterator it = v.begin(); it != v.end(); ++it) {
                    float val = *it;
                    sum += val * val;
                }
                return sqrt(sum);
            }
    };
}

