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
    alpha ~ normal(600, 20); 
    beta_1 ~ normal(-4000, 50);
    beta_2 ~ normal(13000, 50);
    beta_3 ~ normal(-4800, 50);
    beta_4 ~ normal(500, 20);
    sigma ~ normal(200, 10);

    // Linear regression model 
    y ~ normal(alpha + beta_1 * x + beta_2 * x^2 + beta_3 * x^3 + beta_4 * x^4, sigma); 
} 

generated quantities {  
    vector [N] y_sim;

    for(i in 1:N){
        y_sim[i] = normal_rng(alpha + beta_1 * x[i] + beta_2 * x[i]^2 + beta_3 * x[i]^3 + beta_4 * x[i]^4, sigma);
    }
     
}