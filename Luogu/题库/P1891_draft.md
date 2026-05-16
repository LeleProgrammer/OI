$$
\begin{align}
\sum\limits_{i=1}^n lcm(i,n) &= \sum\limits_{i=1}^n \frac{in}{\gcd(i,n)} \\
&= \sum\limits_{i=1}^n \sum\limits_{d=1}^n \frac{in}{d[\gcd(i,n)=d]} \\
&= \sum\limits_{i=1}^n \sum\limits_{d=1}^n \frac{in}{d[\gcd(\frac{i}{d},\frac{n}{d})=1]} \\
&= n \sum\limits_{d|n} \sum\limits_{i=1}^{\frac{n}{d}} i[\gcd(\frac{i}{d},\frac{n}{d})=1] \\
&= n \sum\limits_{d|n} \sum\limits_{i=1}^d i[\gcd(i,d)=1] \\
&= n \sum\limits_{d|n} \frac{\varphi(d)d}{2}
\end{align}
$$

