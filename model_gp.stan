data {
    int<lower=1> N;
    real x[N];
    real y[N];
    int<lower=1, upper=N> idx[N];
    
    real<lower=0> rho;
    real<lower=0> alpha;
    real<lower=0> sigma;
}

transformed data {
    matrix[N, N] cov = cov_exp_quad(x, alpha, rho) + diag_matrix(rep_vector(1e-10, N));
    matrix[N, N] L_cov = cholesky_decompose(cov);
}

parameters {
    vector[N] f_t;
}

transformed parameters {
    vector[N] f = L_cov * f_t;
}

model {
    f_t ~ normal(0,1);
    y ~ normal(f[idx], sigma);
}

generated quantities {
    vector[N] log_lik;
    vector[N] y_sim;
    for (i in 1:N){
        log_lik[i] = normal_lpdf(y[i] | f[i], sigma);
        y_sim[i] = normal_rng(f[i], sigma);
    }
}