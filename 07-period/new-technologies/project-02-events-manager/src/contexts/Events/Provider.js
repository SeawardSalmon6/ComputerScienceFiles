import { createContext, useEffect, useMemo, useReducer, useState } from "react";
import { eventsReducer, loadEventsFromLocalStorage } from "./constants";

export const EventsContext = createContext({});

export function EventsContextProvider({ children }) {
  const [events, eventsDispatcher] = useReducer(eventsReducer, []);

  const value = useMemo(
    () => ({
      events,
      eventsDispatcher,
    }),
    [events]
  );

  useEffect(() => {
    const fetchEvents = async () => {
      const localEvents = await loadEventsFromLocalStorage();
      eventsDispatcher({ type: "loadEvents", payload: localEvents });
    };

    fetchEvents();
  }, []);

  return (
    <EventsContext.Provider value={value}>{children}</EventsContext.Provider>
  );
}
