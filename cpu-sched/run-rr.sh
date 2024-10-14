#!/bin/bash

# Variablen
python_script="./scheduler.py"    # Pfad zum Python-Skript
max_jobs=5                        # Anzahl der Jobs
job_length=10                     # Feste Job-Länge für jeden Job
initial_quantum=1                 # Startwert der Quantum-Länge
increment=2                       # Schrittweite, um die Quantum-Länge zu vergrößern
quantum_limit=20                  # Obergrenze für die Quantum-Länge
output_file="rr_response_times.txt"  # Datei für die Ergebnisse

# Datei für Ergebnisse erstellen
echo "Quantum Length | Average Response Time" > $output_file

# Schleife, um die Quantum-Längen zu vergrößern
for (( quantum=$initial_quantum; quantum<=$quantum_limit; quantum+=$increment ))
do
    echo "Running RR with quantum length = $quantum"

    # Python-Skript mit RR ausführen und Quantum-Länge variieren
    result=$(python3 $python_script -p RR -j $max_jobs -m $job_length -q $quantum -c)

    # Extrahiere die durchschnittliche Response Time aus der Ausgabe
    avg_response_time=$(echo "$result" | grep "Average -- Response" | awk '{print $4}')

    # Schreibe die Quantum-Länge und die durchschnittliche Response Time in die Datei
    echo "$quantum | $avg_response_time" >> $output_file
done

echo "Ergebnisse wurden in $output_file gespeichert."

