(define (domain car-plane-world)
    (:types  plane car - transport
	         person transport place - object)
    (:predicates
        (person		?person - person)
        (place		?place - place)
        (plane		?plane - plane)
		(car		?car - car)
        (at			?transport - transport	?place - place)
		(at			?person - person		?place - place)
        (in			?person - person		?vehicle - transport)
        (has		?person - person		?tickets))
		
	;; A person travels from one place to another using some transport. 
	(:action travel
        :parameters		(?person - person ?from - place ?to - place ?means - transport)

        :precondition	(at ?person ?from)
        
		:effect			(and	(not (at ?person ?from))
								(at ?person ?to))

		:composite		t)

	;; A person gets into a car at a place.
	(:action get-in-car
        :parameters		(?person - person ?car - car ?place - place)

        :precondition	(and	(at ?person ?place)
								(at ?car ?place))

        :effect			(and	(not (at ?person ?place))
								(in ?person ?car)))
   
   	;; A person drives a car from one place to another place.
    (:action drive
        :parameters		(?person - person ?car - car ?from - place ?to - place)
        
        :precondition	(and	(at ?car ?from)
								(in ?person ?car))
        :effect			(and	(not (at ?car ?from))
								(at ?car ?to)))
     
	;; A person gets out of a car at a place.
    (:action get-out-of-car
        :parameters		(?person - person ?car - car ?place - place)
        
        :precondition	(and	(at ?car ?place)
								(in ?person ?car))

        :effect			(and	(not (in ?person ?car))
								(at ?person ?place)))

	;; A person buys tickets.
    (:action buy-tickets
        :parameters		(?person - person)
        
        ;:precondition	()
        :effect			(has ?person tickets))
        
	;; A person boards a plane at a place.
    (:action board-plane
        :parameters		(?person - person ?plane - plane ?place - place)
        
        :precondition	(and	(at ?person ?place)
								(at ?plane ?place)
								(has ?person tickets))
        
		:effect			(and	(not (at ?person ?place))
								(not (has ?person tickets)) 
								(in ?person ?plane)))

    ;; A person flies on a place from one place to another.                
    (:action fly
        :parameters		(?person - person ?plane - plane ?from - place ?to - place)
        
        :precondition	(and	(at ?plane ?from)
								(in ?person ?plane))

        :effect			(and	(not (at ?plane ?from))
								(at ?plane ?to)))
    
	;; A person deplaces at a location.
    (:action deplane
        :parameters		(?person - person ?plane - plane ?place - place)
        
        :precondition	(and	(at ?plane ?place)
								(in ?person ?plane))

        :effect			(and	(not (in ?person ?plane))
								(at ?person ?place)))

	;; Potential travel decomposition: driving
	;; One way to travel from one location to another is to drive there.
    (:decomposition travel
        :name drive
        :parameters		(?person - person ?from - place ?to - place ?car - car)
        :steps			(
					;;	 (step1 (get-in-car ?person ?car ?to))
					;;	 (step2 (drive ?person ?car ?from ?to))
					;;	 (step3 (get-out-of-car ?person ?car ?from))
						)

        ;;:links		(
		;;				 (step1 (in ?person ?car) step2)
		;;				 (step1 (in ?person ?car) step3)
		;;				 (step2 (at ?car ?to) step3)
		;;				)
	)
        
;;    (:decomposition travel
;;        :name travel-by-plane
;;        :parameters (?person - person ?from ?to - place ?plane - plane)
;;        ;:constraints ()
;;        :steps ((step1 (buy-tickets ?person))
;;                (step2 (board-plane ?person ?plane ?from))
;;                (step3 (fly ?person ?plane ?from ?to))
;;                (step4 (deplane ?person ?plane ?to)))
;;        :links ((step1 (has ?person tickets) step2)
;;                (step2 (in ?person ?plane) step3)
;;                (step2 (in ?person ?plane) step4)
;;			    (step3 (at ?plane ?to) step4)))


)