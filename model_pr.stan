data { 
    int <lower = 0> N; 
    vector [N] x;
    vector [N] y; 
} 
 
parameters { 
    real alpha; 
    real beta_1;
    real beta_2; 
    real beta_3;
    real beta_4;
    real <lower = 0> sigma; 
} 
 
model { 
    // Priors 
    alpha ~ normal(610, 5); 
    beta_1 ~ normal(-4000, 5);
    beta_2 ~ normal(12750, 5);
    beta_3 ~ normal(-4800, 5);
    beta_4 ~ normal(510, 5);
    sigma ~ exponential(5);

    // Linear regression model 
    y ~ normal(alpha + beta_1 * x + beta_2 * x^2 + beta_3 * x^3 + beta_4 * x^4, x^1.5*sigma); 
} 

generated quantities {  
    vector [N] y_sim;
    vector [N] log_lik;

    for(i in 1:N){
        log_lik[i] = normal_lpdf(y[i] | alpha + beta_1 * x[i] + beta_2 * x[i]^2 + beta_3 * x[i]^3 + beta_4 * x[i]^4, x[i]^1.5*sigma);
        y_sim[i] = normal_rng(alpha + beta_1 * x[i] + beta_2 * x[i]^2 + beta_3 * x[i]^3 + beta_4 * x[i]^4, x[i]^1.5*sigma);
    }
     
}