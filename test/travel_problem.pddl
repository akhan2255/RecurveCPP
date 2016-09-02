(define (problem travel-to-la)
    (:domain travel)
    (:objects alice bob - person
              accord - car)
    (:init 
        (person bob)
		(person alice)
        (place raleigh)
        (place la)
        (car accord)
		(at alice la)
        (at bob raleigh)
        (at accord raleigh))
        
(:goal (at bob la)))