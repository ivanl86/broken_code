
# Hypothesis Test
# Less Than -> Left Tailed
# Greater Than -> Right Tailed
# Difference -> Two Tailed
# If the p-value <= alpha, we reject the null hypothesis

find_z_c <- function(left_tailed, right_tailed, alpha) {
	if (left_tailed) {
		return(qnorm(alpha, 0, 1))
	} else if (right_tailed) {
		return(qnorm(1 - alpha, 0, 1))
	} else {
		return(qnorm(1 - (alpha / 2), 0, 1))
	}
}

find_t_c <- function(left_tailed, right_tailed, alpha, df) {
	if (left_tailed) {
		return(qt(alpha, df))
	} else if (right_tailed) {
		return(qt(1 - alpha, df))
	} else {
		return(qt(1 - (alpha / 2), df))
	}
}

find_p_value_z_dist <- function(left_tailed, right_tailed, z) {
	if (left_tailed) {
		return(pnorm(z, 0, 1))
	} else if (right_tailed) {
		return(1 - pnorm(z, 0, 1))
	} else {
		if (z <= 0) {
			return(2 * pnorm(z, 0, 1))
		} else {
			return(2 * pnorm(-z, 0, 1))
		}
	}
}

find_p_value_t_dist <- function(left_tailed, right_tailed, t, df) {
	if (left_tailed) {
		return(pt(t,df))
	} else if (right_tailed) {
		return(1 - pt(t, df))
	} else {
		return(2 * pt(t, df))
	}
}

find_CI <- function(PE, critical_value, SE, alpha) {
	cat(sprintf("%d%% confidence interval = (%#.4f, %#.4f)\n", (1 - alpha) * 100, PE - critical_value * SE, PE + critical_value * SE))
}

stat_decision <- function(left_tailed, right_tailed, alpha, test_statistic, critical_value) {
	more_extreme <- "Since the test statistic is MORE extreme than the critical value,"
	reject <- "we REJECT the null hypothesis"
	is <- "There IS statistically significant evidence that..."

	not_more_extreme <- "Since the test statistic is NOT more extreme than the critical value,"
	fail_to_reject <- "we FAIL to reject the null hypothesis"
	is_not <- "There is NOT statistically significant evidence that..."

	if (left_tailed) {
		if (test_statistic < critical_value) {
			cat(sprintf("%s\n%s at the alpha = %#.2f level.\n%s\n", more_extreme, reject, alpha, is))
		} else {
			cat(sprintf("%s\n%s at the alpah = %#.2f level.\n%s\n", not_more_extreme, fail_to_reject, alpha, is_not))
		}	
	} else if (right_tailed) {
		if (test_statistic > critical_value) {
			cat(sprintf("%s\n%s at the alpha = %#.2f level.\n%s\n", more_extreme, reject, alpha, is))
		} else {
			cat(sprintf("%s\n%s at the alpah = %#.2f level.\n%s\n", not_more_extreme, fail_to_reject, alpha, is_not))
		}
	} else {
		if (test_statistic > critical_value || test_statistic < -critical_value) {
			cat(sprintf("%s\n%s at the alpha = %#.2f level.\n%s\n", more_extreme, reject, alpha, is))
		} else {
			cat(sprintf("%s\n%s at the alpah = %#.2f level.\n%s\n", not_more_extreme, fail_to_reject, alpha, is_not))
		}
	}
}

print_stat <- function(left_tailed, right_tailed, test_statistic, critical_value, p_value, alpha) {
	cat(sprintf("Test statistic = %#.4f\n", test_statistic))
	if (left_tailed || right_tailed) {
		cat(sprintf("Critical value = %#.4f\n", critical_value))
	} else {
		cat(sprintf("Critical value = (%#.4f, %#.4f)\n", -critical_value, critical_value))
	}
	cat(sprintf("P-value = %#.8f\n", p_value))
	cat(sprintf("alpha = %#.2f\n", alpha))
}

print_CI <- function(PE, critical_value, SE, alpha) {
	cat(sprintf("Point of Interest = %#.4f\n", PE))
	if (critical_value < 0) {
		cat(sprintf("Critical value = %#.4f\n", -critical_value))
	} else {
		cat(sprintf("Critical value = %#.4f\n", critical_value))
	}
	cat(sprintf("Standard error = %#.4f\n", SE))
	cat(sprintf("At %d%% confidence interval\n", (1 - alpha) * 100))
}

# --------------------
# 1 Proportion -> p = p_0

left_tailed <- F
right_tailed <- F

p_0 <- 0.85
x <- 97
n <- 125
alpha <- 0.10

phat <- x / n
q_0 <- 1 - p_0

z <- (phat - p_0) / sqrt(p_0 * q_0 / n)
z_c <- find_z_c(left_tailed, right_tailed, alpha)
p_value <- find_p_value_z_dist(left_tailed, right_tailed, z)

print_stat(left_tailed, right_tailed, z, z_c, p_value, alpha)
stat_decision(left_tailed, right_tailed, alpha, z, z_c)

qhat <- 1 - phat
SE <- sqrt(phat * qhat / n)
print_CI(phat, z_c, SE, alpha)
find_CI(phat, z_c, SE, alpha)

# --------------------
# 1 Population Mean -> mu = mu_0

left_tailed <- F
right_tailed <- T

mu <- 20
X_bar <- 25
s <- 8.3
n <- 400
alpha <- 0.05

df <- n - 1
t <- (X_bar - mu) / (s / sqrt(n))
t_c <- qt(1 - alpha, df)
p_value <- find_p_value_t_dist(left_tailed, right_tailed, t, df)

print_stat(left_tailed, right_tailed, t, t_c, p_value, alpha)
stat_decision(left_tailed, right_tailed, alpha, t, t_c)

SE <- s / sqrt(n)
print_CI(X_bar, t_c, SE, alpha)
find_CI(X_bar, t_c, SE, alpha)

# --------------------
# Difference in 2 Population Proportions -> p_1 - p_2 = 0

left_tailed <- F
right_tailed <- F

# Group 1
x_1 <- 180
n_1 <- 300
phat_1 <- x_1 / n_1

# Group 2
x_2 <- 135
n_2 <- 250
phat_2 <- x_2 / n_2

alpha <- 0.01

phat_1_2 <- phat_1 - phat_2
p_1_2 <- 0
phat <- (x_1 + x_2) / (n_1 + n_2)
qhat <- 1 - phat
z <- (phat_1_2 - p_1_2) / sqrt(phat * qhat * (1 / n_1 + 1 / n_2))
z_c <- find_z_c(left_tailed, right_tailed, alpha)
p_value <- find_p_value_z_dist(left_tailed, right_tailed, z)

print_stat(left_tailed, right_tailed, z, z_c, p_value, alpha)
stat_decision(left_tailed, right_tailed, alpha, z, z_c)

qhat_1 <- 1 - phat_1
qhat_2 <- 1 - qhat_2
SE <- sqrt(phat_1 * qhat_1 / n_1 + phat_2 * qhat_2 / n_2)
print_CI(phat_1_2, z_c, SE, alpha)
find_CI(phat_1_2, z_c, SE, alpha)

# --------------------
# Population Mean of Paired Difference -> mu_d = 0
# Sigma_d Unknown

left_tailed <- T
right_tailed <- F

mu_d <- 0
X_bar_d <- -65
s_d <- 42
n_d <- 28
alpha <- 0.05

df <- n_d - 1
t <- (X_bar_d - mu_d) / (s_d / sqrt(n_d))
t_c <- find_t_c(left_tailed, right_tailed, alpha, df)
p_value <- find_p_value_t_dist(left_tailed, right_tailed, t, df)


print_stat(left_tailed, right_tailed, t, t_c, p_value, alpha)
stat_decision(left_tailed, right_tailed, alpha, t, t_c)

SE <- s_d / sqrt(n_d)
print_CI(X_bar_d, t_c, SE, alpha)
find_CI(X_bar_d, t_c, SE, alpha)

# --------------------
# Difference in 2 Population Mean for Independent Samples -> mu_1 - mu_2 = 0
# Sigma_1 and Sigma_2 Unknown
# Sigma_1 != Sigma_2

left_tailed <- F
right_tailed <- F

# Group 1
mu_1 <- 0
X_bar_1 <- 2.1
s_1 <- 1.3
n_1 <- 10

# Group 2
mu_2 <- 0
X_bar_2 <- 2.5
s_2 <- 1.1
n_2 <- 14

alpha <- 0.10

vector <- c(n_1 - 1, n_2 - 1)
df <- min(vector)
SE <- sqrt((s_1^2 / n_1) + (s_2^2 / n_2))
t <- ((X_bar_1 - X_bar_2) - (mu_1 - mu_2)) / SE
t_c <- find_t_c(left_tailed, right_tailed, alpha, df)
p_value <- find_p_value_t_dist(left_tailed, right_tailed, t, df)

print_stat(left_tailed, right_tailed, t, t_c, p_value, alpha)
stat_decision(left_tailed, right_tailed, alpha, t, t_c)

print_CI(X_bar_1 - X_bar_2, t_c, SE, alpha)
find_CI(X_bar_1 - X_bar_2, t_c, SE, alpha)

# --------------------
# Linear Regression
X_bar <- 15
SSE <- 34.5
S_xx <- 15.2
n <- 30
df <- n - 2
S_e <- sqrt(SSE / df)
B0_SE <- S_e * sqrt(1 / n + X_bar^2 / S_xx)
B1_SE <- S_e * sqrt(1 / S_xx)

B0_SE
B1_SE









