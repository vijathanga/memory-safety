
if [ "$1" == "" ];
then
    echo "Usage: $0 <program_name>"
    exit 1;
fi

PRG=$1
LOG_FILE="plot/$PRG/$PRG"

rm -rf "plot/$PRG" 2> /dev/null
mkdir "plot/$PRG"






echo "Compiling for splint"
clang -o $PRG "$PRG.c" -lm -lrt

{ time "./$PRG"; } 1> "plot/$PRG/meta.splint" 2>&1 &

echo "Splint program started"

while [ $? == 0 ]
do
    sleep 0.001
    ps -C $PRG -o pid=,rss= >> "$LOG_FILE.splint"
done

echo "Splint program terminated"





echo "Compiling for SB+CETS"
clang -fsoftboundcets "$PRG.c" -o "$PRG" -L../../../softboundcets-lib -lm -lrt

{ time "./$PRG"; } 1> "plot/$PRG/meta.cets" 2>&1 &

echo "SB+CETS program started"

while [ $? == 0 ]
do
    sleep 0.001
    ps -C "$PRG" -o pid=,rss= >> "$LOG_FILE.cets"
done

echo "SB+CETS program terminated"



gnuplot -c graph.gp $PRG

rm $PRG