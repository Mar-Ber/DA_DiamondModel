data { 
    int <lower = 0> N; 
    vector [N] carat;
    vector [N] price; 
} 
 
parameters { 
    real alpha; 
    real beta; 
    real <lower = 0> sigma; 
} 

transformed parameters {
    vector[N] mu;
    for (i in 1:N) {
        mu[i] = alpha + beta * carat[i];
    }
}

model { 
    alpha ~ normal(200, 20); 
    beta ~ normal(5600, 50); 
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