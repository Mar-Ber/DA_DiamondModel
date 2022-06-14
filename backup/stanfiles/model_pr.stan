data { 
    int <lower = 0> N; 
    vector [N] carat;
    vector [N] price; 
} 
 
parameters { 
    real alpha; 
    real beta_1;
    real beta_2; 
    real beta_3;
    real beta_4;
    real <lower = 0> sigma; 
} 

transformed parameters {
    vector[N] mu;
    for (i in 1:N) {
        mu[i] = alpha + beta_1 * carat[i] + beta_2 * carat[i]^2 + beta_3 * carat[i]^3 + beta_4 * carat[i]^4;
    }
}

model { 
    alpha ~ normal(617, 5); 
    beta_1 ~ normal(-3957, 5);
    beta_2 ~ normal(12740, 5);
    beta_3 ~ normal(-4797, 5);
    beta_4 ~ normal(515, 5);
    sigma ~ exponential(5);

    price ~ normal(mu, sigma); 
} 

generated quantities {  
    vector [N] price_sim;
    vector [N] log_lik;

    for(i in 1:N){
        log_lik[i] = normal_lpdf(price[i] | mu[i], sigma);
        price_sim[i] = normal_rng(mu[i], sigma);
    }
     
}