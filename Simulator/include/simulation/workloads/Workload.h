#pragma once
#include <stdint.h>

namespace Simulation
{
	/*
		The Workload class models a workload.
	*/
	class Workload
	{
	public:
		/*
			Initializes the TOTAL_FLOPS and the remainingFlops to the size.
		*/
		Workload(int size, int startTick, int dbId, int traceId, int dependency);

		/*
			Decreases the remainingFlops by the given amount.
		*/
		void doOperations(uint32_t opCount);

		/*
			Returns the amount of operations left to do.
		*/
		uint32_t getRemainingOperations() const;

		/*
			Returns the total amount of operations, including finished ones.
		*/
		uint32_t getTotalOperations() const;

		/*
			Returns true if the workload has been finished.
		*/
		bool isFinished() const;
		
		/*
			Returns the id of this workload.
		*/
		uint32_t getId() const;

		/*
			Returns the dependency id of this workload.
		*/
		int getDependencyId() const;

		/**
		 * \return The start tick of this workload.
		 */
		uint32_t getStartTick() const
		{
			return START_TICK;
		}

		// True if the dependency of this workload has finished.
		bool dependencyFinished = false;

	private:
		// The id of the workload this workload depends on.
		int dependencyId;

		// Finished is true if the remainingFlops is 0.
		bool finished = false;

		// The amount of operations done.
		uint32_t remainingFlops;

		// The total amount of operations required to finish this task.
		uint32_t TOTAL_FLOPS;

		// The tick during which this workload was started.
		uint32_t START_TICK;

		// The id of this workload in the database
		uint32_t ID;

		// The id of the trace this workload belongs to in the database.
		uint32_t TRACE_ID;
	};
}
