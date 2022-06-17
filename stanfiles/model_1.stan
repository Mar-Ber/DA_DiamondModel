data {
    int N;
    vector[N] carat;
    array [N] int <lower=1, upper=8> cut;
    vector[N] price;
}

parameters {
    vector[8] alpha_cut;
    vector[8] beta_cut;
    real <lower=0> sigma;
}

transformed parameters {
    array [N] real mu;
    for (i in 1:N){
        mu[i] = alpha_cut[cut[i]] + beta_cut[cut[i]] * carat[i];
    } 
}

model {
    alpha_cut ~ normal(-1000,10);
    beta_cut ~ normal(8000,1800);
    sigma ~ exponential(10);

    for (i in 1:N){
        price[i] ~ normal(mu[i], sigma);
    }
}

generated quantities {
    vector[N] price_sim;
    vector[N] log_lik;
    for (i in 1:N){
        price_sim[i] = normal_rng(mu[i], sigma);
        log_lik[i] = normal_lpdf(price[i] | mu[i], sigma);
    }
}