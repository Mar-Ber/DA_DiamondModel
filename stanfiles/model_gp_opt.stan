data {
    int<lower = 1> N;
    real carat[N];
    vector[N] price;
}

parameters {
    real<lower=0, upper=130> alpha;
    real<lower=0, upper=1> rho;
    real<lower=0, upper=100> sigma;
}

model {
    matrix[N, N] cov = cov_exp_quad(carat, alpha, rho) + diag_matrix(rep_vector(square(sigma), N));
    matrix[N, N] L_cov = cholesky_decompose(cov);
    
    price ~ multi_normal_cholesky(rep_vector(0, N), L_cov);
}