#!/bin/sh

#examples
#https://www.duckdns.org/update?domains=ben&token=064a0540-864c-4f0f-8bf5-23857452b0c1&ip=

#rover
#token = e535f3b5-cd41-45e1-a033-92b66291c1f2
#https://www.duckdns.org/update?domains=rover&token=e535f3b5-cd41-45e1-a033-92b66291c1f2&ip=


#curl -k -X POST "https://www.duckdns.org/update?domains=rover&token=e535f3b5-cd41-45e1-a033-92b66291c1f2&ip="


domainParam="rover"
tokenParam="e535f3b5-cd41-45e1-a033-92b66291c1f2"
 
fullHost="https://www.duckdns.org/update?domains=${domainParam}&token=${tokenParam}&ip="
 
updateTime=`date`
logFile="/var/log/duckdns/duckit.log"
 
curlResponse=`curl -m 15 -k -w " %{http_code}\n" "${fullHost}"`
 
logMessage="${updateTime},${curlResponse}"
 
echo ${logMessage} >> ${logFile}
 
exit
