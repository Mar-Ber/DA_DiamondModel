data { 
    int <lower = 0> N; 
    vector [N] x;
    vector [N] y; 
} 
 
parameters { 
    real alpha; 
    real beta; 
    real <lower = 0> sigma; 
} 
 
model { 
    // Priors 
    alpha ~ normal(200, 20); 
    beta ~ normal(5600, 50); 
    sigma ~ exponential(5);

    // Linear regression model 
    y ~ normal(alpha + beta * x, x^1.5 * sigma); 
} 

generated quantities {  
    vector [N] y_sim;
    vector [N] log_lik;

    for(i in 1:N){
        log_lik[i] = normal_lpdf(y[i] | alpha + beta * x[i], x[i]^1.5 * sigma);
        y_sim[i] = normal_rng(alpha + beta * x[i], x[i]^1.5 * sigma);
    }
     
}