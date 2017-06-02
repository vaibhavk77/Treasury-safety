import time
import serial
import smtplib
import socket
TO = ['owner@domain.com','security@domain.com','police@domain.com']
GMAIL_USER = 'server@domain.com'
GMAIL_PASS = 'serverpassword'
SUBJECT = 'Intrusion!!'
TEXT = 'Your PIR sensor detected movement'
ser = serial.Serial('COM3', 9600)

#host = '192.168.43.55'      # Get local machine name
#port = 12345                # Reserve a port for your service.
 
#st = ""
#s = socket.socket()
def send_email(): 

	for t in TO:
		print("Sending Email")
		smtpserver = smtplib.SMTP("smtp.gmail.com",587)
		smtpserver.ehlo()
		smtpserver.starttls()
		smtpserver.ehlo
		smtpserver.login(GMAIL_USER, GMAIL_PASS)
		header = 'To:' + t + '\n' + 'From: ' + GMAIL_USER
		header = header + '\n' + 'Subject:' + SUBJECT + '\n'
		print header
		msg = header + '\n' + TEXT + ' \n\n'
		smtpserver.sendmail(GMAIL_USER, t, msg)
		smtpserver.close()
while True:
	message = ser.readline()
	#ser.write(str(chr(67)))
	print(message)
	if message[0] == 'A':
		send_email("Your PIR sensor has detected motion !!!")
	else:
		send_email("Motion has stopped!!")
time.sleep(7)
