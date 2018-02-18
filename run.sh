./script.sh urls.txt
python read_files.py IPv4.txt processed_ipv4.txt
python read_files.py IPv6.txt processed_ipv6.txt
cat processed_ipv4.txt | sort | uniq > router-topology-v4.dot
echo 'graph routertopology {' | cat - router-topology-v4.dot > f && mv f router-topology-v4.dot
echo '}' >> router-topology-v4.dot
cat processed_ipv6.txt | sort | uniq > router-topology-v6.dot
echo 'graph routertopology {' | cat - router-topology-v6.dot > f && mv f router-topology-v6.dot
echo '}' >> router-topology-v6.dot
dot -Tpdf router-topology-v4.dot -o router-topology-v4.pdf
dot -Tpdf router-topology-v6.dot -o router-topology-v6.pdf