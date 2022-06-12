data {
    int<lower=1> N;
    real carat[N];
    real price[N];
    int<lower=1, upper=N> idx[N];
    
    real<lower=0> alpha;
    real<lower=0> rho;
    real<lower=0> sigma;
}

transformed data {
    matrix[N, N] cov = cov_exp_quad(carat, alpha, rho) + diag_matrix(rep_vector(1e-10, N));
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
    price ~ normal(f[idx], sigma);
}

generated quantities {
    vector[N] log_lik;
    vector[N] price_sim;
    for (i in 1:N){
        log_lik[i] = normal_lpdf(price[i] | f[i], sigma);
        price_sim[i] = normal_rng(f[i], sigma);
    }
}