data {
    int N;
    vector[N] c_carat;
    array [N] int <lower=1, upper=5> cut;
    array [N] int <lower=1, upper=8> clarity;
    vector[N] price;
}

parameters {
    vector[5] alpha_cut;
    vector[8] alpha_clarity;
    vector[5] beta_cut;
    vector[8] beta_clarity;
    real <lower=0> sigma;
}

transformed parameters {
    array [N] real mu;
    for (i in 1:N){
        mu[i] = alpha_cut[cut[i]] + alpha_clarity[clarity[i]] + (beta_cut[cut[i]] + beta_clarity[clarity[i]]) * c_carat[i];
    } 
}

model {
    alpha_cut ~ normal(0,10);
    alpha_clarity ~ normal(0,10);
    beta_cut ~ normal(0,10);
    beta_clarity ~ normal(0,10);
    sigma ~ normal(0,10);

    for (i in 1:N){
        price[i] ~ normal(mu[i], sigma);
    }
}

generated quantities {
    real price_sim [N];
    for (i in 1:N){
        price_sim[i] = normal_rng(mu[i], sigma);
    }
}