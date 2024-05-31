import { Layout } from "../../components/Layout";
import { EventsList } from "../../components/EventsList";
import { Header } from "../../components/Header";
import { useEventsContext } from "../../contexts/Events/useEventsContext";
import { useEffect, useState } from "react";
import { SearchBar } from "../../components/SearchBar";
import { useAppNavigation } from "../../hooks/useAppNavigation";
import { filterEvents } from "../../contexts/Events/constants";

export function Events() {
  const { events, eventsDispatcher } = useEventsContext();
  const [filteredEvents, setFilteredEvents] = useState(events);
  const { goTo } = useAppNavigation();

  const [favorites, nonFavorites] = filteredEvents.reduce(
    (acc, event) => {
      acc[event.favorite ? 0 : 1].push(event);
      return acc;
    },
    [[], []]
  );

  const onSearch = (text) => {
    const newEvents = filterEvents(
      events,
      {
        title: text,
        location: text,
      },
      { relation: "OR" }
    );

    setFilteredEvents(newEvents);
  };

  useEffect(() => {
    setFilteredEvents(events);
  }, [events]);

  return (
    <Layout>
      <Layout.Header
        title="Eventos"
        actions={{
          add: () => goTo("EditEvent", { event: null }),
          delete: () => eventsDispatcher({ type: "reset" }),
        }}
      >
        <SearchBar onSearch={onSearch} />
      </Layout.Header>
      <Layout.Content>
        <Header>Todos os eventos</Header>
        <EventsList events={[...favorites, ...nonFavorites]} showEditAction />
      </Layout.Content>
    </Layout>
  );
}
