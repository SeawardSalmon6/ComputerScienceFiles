import AsyncStorage from "@react-native-async-storage/async-storage";
import { getNextId } from "../../utils/getNextId";

export const FILTER_FIELDS = {
  title: "includes",
  date: "equal",
  location: "includes",
};

export const EVENT_FIELDS = [
  "title",
  "description",
  "location",
  "date",
  "time",
  "price",
  "available",
  "image",
];

export const filterEvents = (
  events,
  filters = {},
  { relation = "AND" } = {}
) => {
  const filterType = relation === "OR" ? "some" : "every";

  const filtered = events.filter((event) => {
    return Object.entries(filters)[filterType](([key, value]) => {
      if (!value) {
        return true;
      }

      if (!FILTER_FIELDS[key]) {
        return true;
      }

      if (FILTER_FIELDS[key] === "includes") {
        return event[key].includes(value);
      }

      return event[key] === value;
    });
  });

  return filtered;
};

export const isEventPayloadValid = (payload) => {
  const payloadKeys = Object.keys(payload);
  const isValid = EVENT_FIELDS.every((field) => payloadKeys.includes(field));
  return isValid;
};

export const loadEventsFromLocalStorage = async () => {
  try {
    const events = await AsyncStorage.getItem("events");
    return events ? JSON.parse(events) : [];
  } catch {
    return [];
  }
};

export const saveEventsToLocalStorage = async (users) => {
  try {
    await AsyncStorage.setItem("events", JSON.stringify(users));
  } catch {
    console.error("Failed to save events to local storage");
  }
};

export const EVENTS_ACTIONS = {
  create: (state, payload) => {
    if (!isEventPayloadValid(payload)) {
      return state;
    }

    const newEvent = {
      ...payload,
      favorite: false,
      id: String(getNextId(state)),
    };

    return [...state, newEvent];
  },
  delete: (state, payload) => {
    return state.filter((event) => event.id !== payload.id);
  },
  update: (state, payload) => {
    if (!isEventPayloadValid(payload)) {
      return state;
    }

    return state.map((event) =>
      event.id === payload.id
        ? { ...event, ...payload, id: String(event.id) }
        : event
    );
  },
  favorite: (state, payload) => {
    return state.map((event) =>
      event.id === payload.id ? { ...event, favorite: !event.favorite } : event
    );
  },
  buyTicket: (state, payload) => {
    return state.map((event) =>
      event.id === payload.id
        ? {
            ...event,
            tickets: [...event.tickets, ...payload.tickets],
            available: event.available - payload.tickets.length,
          }
        : event
    );
  },
  cancelTicket: (state, payload) => {
    return state.map((event) =>
      event.id === payload.id
        ? {
            ...event,
            tickets: event.tickets.filter(
              (ticket) => !payload.tickets.includes(ticket.id)
            ),
            available: event.available + payload.tickets.length,
          }
        : event
    );
  },
  reset: () => [],
  loadEvents: (_, payload) => payload,
};

export const eventsReducer = (state, action) => {
  const { payload, type } = action;
  const eventAction = EVENTS_ACTIONS[type];
  const newState = eventAction ? eventAction(state, payload) : state;

  saveEventsToLocalStorage(newState);
  return newState;
};
