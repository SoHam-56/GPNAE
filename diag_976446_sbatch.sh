#!/bin/bash
#SBATCH --job-name=diag
#SBATCH --cpus-per-task=1
#SBATCH --ntasks=1
#SBATCH --partition=sp-8-gb-1-cores
#SBATCH --output=/proj/work/spramanik/sienna_jobs/runs/timing/diag_make.log
#SBATCH --error=/proj/work/spramanik/sienna_jobs/runs/timing/diag_make.log
#SBATCH --mail-type=TIME_LIMIT
#SBATCH --mail-user=spramanik@tsavoritesi.com
#SBATCH --nodes=1
#SBATCH --mem=2G
#SBATCH --time=0:10:00
export LOCALDOMAIN="$LOCALDOMAIN tsavoritesi.net"
echo running on $(hostname)
echo jobid=$SLURM_JOB_ID
echo start time: $(date)
# Check if job was restarted
if [[ ${SLURM_RESTART_COUNT:-0} -gt 0 ]]; then
    echo "Job was requeued and restarted."
    echo SLURM_RESTART_COUNT=${SLURM_RESTART_COUNT}
fi
/usr/bin/time bash /users/spramanik/.claude/jobs/1fb2ed13/tmp/diag.sh
sleep 2
