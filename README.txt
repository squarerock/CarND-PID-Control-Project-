I started to implement Twiddle in C++ but encountered issues all along the way. I looked up in the forums and even the slack channels but there were some issues in setting up Twiddle in C++. So, I am submitting the manually tweaked values along with how I reached at these hyper parameters.

Reflection:

PID Controller comprises of P, I, D components.
	P:
		This contribution is proportional to the error (in our case, cross-track error). If error is too high, the correction could be too high and the car might oscillate a lot for small errors. If error is too low, the correction would be too less for a big error and the car might go out of track. Error is multiplied by constant Kp.

	I:
		This contribution takes into consideration all past errors and acts on that information. This is proportional to the magnitude of the error and also the duration of the error. Error is multiplied by constant Ki.

	D:
		This contribution takes into consideration the rate of change of error. This predicts the system behavior and acts to correct it quickly. Error is multiplied by constant Kd.

Parameters that need to be tweaked were: Kp, Ki, Kd.
	I started with random Kp, Ki and Kd values of 1, 0, 0.25. This made the car go out of track very quickly. I could see that the error became higher and the controller was not correcting the behavior on time. I lowered the Kp value to 0.5. This made the car go a little further than before but the car started osciallating more and more. 

	Now, I increased the Kd term to 1.0 and the car was able to take first turn but was still very wobbly. Now, I reduced the Kp term a little further to 0.25 to reduce the affect of error on the steering angle as the damping is taking place. This made the car move a lot further but the osciallations were still an issue. 

	So, I increased the Kd to 2.0 and also added the Ki value of 0.0001 (in lecture notes, the term was 0.0004, so added a small value). This made the car behave much better but there were small oscillations here and there. The affect of adding an Ki term were very apparent as the osciallations died down very quickly if they were introduced at some point during the turns. As the cummulative errors kept on adding up, the steering correction because of Ki came into play and damped down the osicllations. 

	To make the osciallations reduce further, I changed the Kd term to 2.5 and the car performed very smooth for the most part. So my Kp Ki and Kd values at this point were 0.25, 0.0001, 2.5

	I noticed that increasing Kd term tends to reduce the osciallations. Just to see what the affect of drastically increasing Kd, I changed Kd to 10 and also increased by Ki to 0.0005 to correct any errors my Kd might make. These values gave me the best performance so far. Any osciallations that the car was exhibiting were quickly corrected and for the most part, the car behaved very smoothly. 

	My final hyper paramters:
	Kp = 0.25
	Ki = 0.0005
	Kd = 10
