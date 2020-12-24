def leaky_bucket(output,bucket_size):
    print('-----*****-----')
    print(f'The output rate is : {output}')
    print(f'The bucket size is : {bucket_size} capacity')
    packet_no = int(input('Enter number of packets you want to send : '))

    for i in range(packet_no):
        packet_size = int(input('Enter packet size : '))
        if packet_size<bucket_size :
            if packet_size <= output:
                print(f'Packet number {i} | Packet Size {packet_size} => ')
                print('Bucket Output Successful!')
                print(f'Last {packet_size} bytes sent.')
                print('-----*****-----')
            else:
                print(f'Packet number {i} | Packet Size {packet_size} => ')
                print('Bucket Output Successful!')
                sent = packet_size - output
                print(f'Last {sent} bytes sent')
                print('-----*****-----')
        else:
            print(f'Packet number {i} | Packet Size {packet_size} => ')
            print('Bucket *Overflow*')
            print('-----*****-----')

output = int(input('Enter Output Rate : '))
bucket_size = int(input('Enter the bucket size : '))

leaky_bucket(output,bucket_size)