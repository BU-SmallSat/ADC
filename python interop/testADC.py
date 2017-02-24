import pexpect, os
from time import sleep
from datetime import datetime


class ADCRunner:
    @staticmethod
    def date2num()->[]:
        now = datetime.utcnow()
        return [now.year,now.month,now.day,now.hour,now.minute,now.second]


    def process_output(self,values: str) -> ():
        floats = [float(f) for f in values.split(',') if values and f]
        # if len(floats) == 7:
        mag = (floats[0], floats[1], floats[2])
        quat = (floats[3], floats[4], floats[5], floats[6])
        return (mag, quat)

    def format_input(self,invals: {}) -> bytes:
        concat = lambda s, f: ''.join([f % x for x in s])
        retval = ''
        retval += concat(invals['mag_meas'], '%3.2f,')
        retval += concat(invals['euler_angle'], '%3.2f,')
        retval += concat(invals['sun_meas'], '%3.2f,')
        retval += concat(invals['epoch'], '%02.0f,')
        retval += concat(invals['lla'], '%3.2f,')
        retval += concat([invals['s_flag']], '%1.0f,')
        retval = retval[:-1] #remove the trailing comma
        retval += '\n'
        return retval.encode('utf-8')

    def page(self,input: {}) -> ():
        formatted = self.format_input(input)
        self.pid.write(formatted)
        response = self.pid.readline()

        return self.process_output(response.decode())

    def __init__(self):

        self.pid = pexpect.spawn('./ADC.elf')
        self.pid.setecho(False)

    def exit(self):
        self.pid.terminate()



if __name__ == "__main__":
    testData = {'mag_meas': [1, 2, 3],
                'euler_angle': [4, 5, 6],
                'sun_meas': [7, 8, 9],
                'epoch': [0, 1, 2, 3, 4, 5],
                'lla': [6, 7, 8],
                's_flag': 9
                }
    runner = ADCRunner()
    i = 0
    while i < 100:

        result = runner.page(testData)
        print(result)
        i += 1
        sleep(.1)



    runner.exit()
