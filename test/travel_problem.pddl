(define (problem travel-to-la)
    (:domain travel)
    (:objects bob - person
              raleigh la - place
              accord - car)
    (:init 
        (person bob)
        (place raleigh)
        (place la)
        (car accord)
        (at bob raleigh)
        (at accord raleigh))
        
(:goal (at bob la)))