-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";

-- check the interviews
SELECT id,transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;

-- find people with the liscence plates that left over the span of 10 minutes after the theft 
SELECT name FROM people 
WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour= 10 AND minute >= 15 AND minute <25);

-- suspects are: Patrick, Amber, Elizabeth, Roger, Danielle, Russell, Evelyn And Ernest

-- another query to find person's name through their bank account
SELECT name FROM people
WHERE id in (SELECT person_id FROM bank_accounts
WHERE account_number IN 
(SELECT account_number 
FROM atm_transactions
WHERE year = 2020 
AND month = 7 
AND day = 28 
AND atm_location = 'Fifer Street' 
AND transaction_type ='withdraw'));
-- suspects from this query are : Bobby, Elizabeth, Victoria, Madison, Roy, Danielle, Russell And Ernest

-- suspects at this point: Elizabeth, Danielle, Russell and Ernest


-- FIND OUT THE CALLER
SELECT DISTINCT name FROM people 
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year =2020 AND month =7 AND day = 28 AND duration <= 60);
--callers: Bobby, Roger, Victoria, Madison, Russell, Evelyn, Kathryn, Ernest and Kimberly

-- suspects at this point: Russell and Ernest

 -- people who were on the flight
SELECT DISTINCT name from people
JOIN passengers
ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE day = '29' AND month = '7' and year = '2020' ORDER BY hour,minute LIMIT 1);
-- people on the flight: Dories, Roger, Ernest, Edward, Evelyn, Madison, Bobby and Danielle

-- the thief is Ernest
-- destination city
SELECT city FROM airports
WHERE ID = (SELECT destination_airport_id FROM flights
WHERE origin_airport_id = (SELECT id FROM airports WHERE city ='Fiftyville')
AND year = 2020 AND month = 7 AND day =29 ORDER BY hour,minute LIMIT 1);

-- city is LONDON

-- find out her accomplice 
SELECT DISTINCT name FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver 
WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration <60 
AND caller = (SELECT phone_number FROM people WHERE name ='Ernest'));

-- accomplice is Berthold
