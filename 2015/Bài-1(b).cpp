void init( A &a ) {
			A b;
			a.~A();
			a = b;
		}