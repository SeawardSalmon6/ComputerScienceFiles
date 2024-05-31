import { useContext } from "react";
import { EventsContext } from "./Provider";

export function useEventsContext() {
  return useContext(EventsContext);
}
