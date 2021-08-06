import csv
from sklearn.metrics import auc


#change this to change what file currently analyzing
file = "results-withdrawal-bup9.csv"

def DA_AUC(data):
    """
    Area under curve of dopamine line

    % of control
    """
    xs = []
    ys =[]
    for row in data:
        xs.append(row[0])
        ys.append(row[2]) #DA0 for now idrk
    print(auc(xs,ys))

def get_spikes_info(data):
    begin = 0 # 0 when looking for beginning, 1 when looking for stop
    spike_info = []
    t0 = 0
    tf = 0
    for row in data:

        if row[1] > -30 and begin == 0:
            begin = 1
            t0 = row[0]

        elif row[1] < -30 and begin == 1:
            begin = 0
            tf = row[0]
            spike_info.append([t0,tf])
    return spike_info


def count_single_spikes_and_bursts(info):
    """
    how many single spikes (not bursts) in this 10s simulation
    how many bursts in this 10s simulation

    burst was defined as a train of 2 or more spikes initiated
    by an inter-spike interval (ISI) of 80 ms and terminated by an ISI > 160 ms
    """

    singles = 0
    bursts = 0
    inBurst = False

    spikesperbursts = []
    spb = 2

    prev_start = -1000
    prev_end = -1000
    for spike in info:
        if spike[0] - prev_end > 80:
            #print('single:', spike[0])
            singles += 1
            if inBurst:
                spikesperbursts.append(spb)
            inBurst = False
        else:
            #print('burst:',inBurst, spike[0])
            if not inBurst:
                spb = 2
                singles -=1
                bursts += 1
            else:
                spb += 1
            inBurst = True
        prev_start = spike[0]
        prev_end = spike[1]
    return singles, bursts, spikesperbursts, sum(spikesperbursts)/len(spikesperbursts)


with open(file) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter = ',')
    line_count = 0
    data = []
    for row in csv_reader:
        if line_count == 0:
            line_count += 1
            continue
        else:
            data.append(list(map(float,row))) #t, v, da0, da1
    info = get_spikes_info(data)
    #print(info)
    #print(len(info))
    print(file)
    print(count_single_spikes_and_bursts(info))
    DA_AUC(data)

#make it actually random later and do t-test or something
