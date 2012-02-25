(defun fib (n)
  ;; This is a method for computing the nth Fibonacci number in an O(log n)
  ;; manner.
  ;; You may have known how to do this via a matrix. However, this method is
  ;; just more simple and elegant.
  ;; If we define the multiplication on ordered pairs to be
  ;; (a, b) (p, q) = (ap + aq + bp, ap + bq)
  ;; Then the Fibonacci transformation T is just a special case of p = 0 and
  ;; q = 1, so the nth Fibonacci number can be computed via an ordered pair
  ;; (1, 0) multiplies transformation T for n times.
  ;; T ^ n can be computed in a fast binary method, so the time complexity is
  ;; O(log n).
  ;; This method was first found in the book Structure and Interpretation of
  ;; Computer Programs (Exercise 1.19). Note that this implementation makes
  ;; some modifications from the original code.
  (fib-iter 1 0 1 0 n))
(defun fib-iter (a b p q count)
  ;; The iteration.
  ;; Use the definition given before, we know that
  ;; (p, q) (p, q) = (2pq + pp, pp + qq)
  (cond ((= count 0) b)
        ((evenp count)
         (fib-iter a 
                   b 
                   (+ (* 2 p q) (* p p))
                   (+ (* p p) (* q q))
                   (/ count 2)))
        (t (fib-iter (+ (* a p) (* a q) (* b p))
                     (+ (* a p) (* b q))
                     p
                     q
                     (- count 1)))))
