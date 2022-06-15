data { 
    int <lower = 0> N; 
    vector [N] carat;
    vector [N] clarity;
    vector [N] price; 
} 
 
parameters { 
    real alpha; 
    real beta_1; 
    real beta_2; 
    real <lower = 0> sigma; 
} 

transformed parameters {
    vector[N] mu;
    for (i in 1:N) {
        mu[i] = alpha + beta_1 * carat[i] + beta_2 * carat[i];
    }
}

model { 
    alpha ~ normal(-1500, 100); 
    beta_1 ~ normal(7000, 1000); 
    beta_2 ~ normal(-250, 10);
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