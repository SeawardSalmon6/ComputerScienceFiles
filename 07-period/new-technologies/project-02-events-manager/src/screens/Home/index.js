import { Layout } from "../../components/Layout";
import { EventsList } from "../../components/EventsList";
import { Header } from "../../components/Header";
import { useEventsContext } from "../../contexts/Events/useEventsContext";
import { styles } from "./styles";
import { useEffect, useState } from "react";
import { filterEvents } from "../../contexts/Events/constants";

export function Home() {
  const { events } = useEventsContext();
  const [filteredEvents, setFilteredEvents] = useState(events);

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
      <Layout.Header title="Home" onSearch={onSearch} />
      <Layout.Content>
        <Header>Eventos favoritos</Header>
        <EventsList
          containerStyle={styles.favoritesContainer}
          events={favorites}
          horizontal
          emptyText={`Favorite seu primeiro evento.\nEles aparecerão aqui.`}
        />
        <Header>Eventos</Header>
        <EventsList
          events={nonFavorites}
          emptyText={`Ainda não temos eventos disponíveis.\nVolte mais tarde!`}
        />
      </Layout.Content>
    </Layout>
  );
}
