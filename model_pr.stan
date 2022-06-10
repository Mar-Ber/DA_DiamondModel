data { 
    int <lower = 0> N; 
    vector [N] x;
    vector [N] y; 
} 
 
parameters { 
    real alpha; 
    real beta;
    real gamma; 
    real delta;
    real eps;
    real <lower = 0> sigma; 
} 
 
model { 
    // Priors 
    alpha ~ normal(600, 20); 
    beta ~ normal(-4000, 50);
    gamma ~ normal(13000, 50);
    delta ~ normal(-4800, 50);
    eps ~ normal(500, 20);
    sigma ~ normal(200, 10);

    // Linear regression model 
    y ~ normal(alpha + beta * x + gamma * x^2 + delta * x^3 + eps * x^4, sigma); 
} 

generated quantities {  
    vector [N] y_sim;

    for(i in 1:N){
        y_sim[i] = normal_rng(alpha + beta * x[i] + gamma * x[i]^2 + delta * x[i]^3 + eps * x[i]^4, sigma);
    }
     
}