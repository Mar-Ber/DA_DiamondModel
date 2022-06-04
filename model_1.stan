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
    sigma ~ normal(200, 50);

    // Linear regression model 
    y ~ normal(alpha + beta * x, sigma); 
} 

generated quantities {  
    vector [N] y_sim;

    for(i in 1:N){
        y_sim[i] = normal_rng(alpha + beta * x[i], sigma);
    }
     
}